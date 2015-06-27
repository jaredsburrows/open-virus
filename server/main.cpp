/* Copyright (C) 2015 OpenVirus by Jared Burrows <jaredsburrows@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>
#include <thread>
#include <cstdio>

#include <dlfcn.h>

#include <ov/server/shell.hpp>
#include <ov/module/module.hpp>


auto commandListener() -> void {

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
}

auto keepAlive() -> void {

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

}

// Load modules
// Listen for commands
// Send data to remote server
// Run commands remotely

// Actions
// 1. lauch theread for sending data
// // send "keep-alive" - to C&C server
// 2. launch thread of conncetions

static const int NUMBER_ARGS = 2;

int main(const int argc, const char** argv) {

    // if (argc != NUMBER_ARGS) {
    //     printf("%s [Port]\n", argv[0]);
    //     return EXIT_FAILURE;
    // }


    for (int i = 1; i < argc; ++i) {
        void* shared_library = dlopen(argv[i], RTLD_LAZY);
        Module* (*load)() = reinterpret_cast<Module* (*)()>(dlsym(shared_library, "load"));
        Module* module;
        if (load) {
            module = load();
            module->run();
            // module->say();
            std::cout << module->name() << "\n";
        } else {
            std::cerr << "Error while loading: " << argv[i] << "\n";
        }
    }



    return 0;
}

