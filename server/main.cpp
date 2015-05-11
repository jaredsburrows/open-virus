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
#include <cstdio>
#include <thread>

#include "shell.hpp"


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


class Request {
public:
    Request& withA();
    Request& withB();
    Request& withC();
};

Request& Request::withA() {
    return *this;
}

Request& Request::withB() {
    return *this;
}

Request& Request::withC() {
    return *this;
}

// Actions
// 1. lauch theread for sending data
// // send "keep-alive" - to C&C server
// 2. launch thread of conncetions

static const int NUMBER_ARGS = 2;

int main(const int argc, const char** argv) {

    if (argc != NUMBER_ARGS) {
        printf("%s [Port]\n", argv[0]);
        return EXIT_FAILURE;
    }


    Request r;
    r.withA().withB().withC();

    Shell s;
    std::cout << s.runCommand("ls") << std::endl;
    std::cout << s.runCommand("ls", 100) << std::endl;


  return 0;
}

