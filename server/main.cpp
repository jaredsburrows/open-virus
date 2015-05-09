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
#include <functional>
#include <ctime>

// C++11 headers
#include <atomic>
#include <chrono>
#include <unordered_map>
#include <thread>

// use using
using sysclock = std::chrono::system_clock;


// C++11 compile-time assertion
static_assert(sizeof(void*) == sizeof(char*), "compile time assertion failed");


std::string now () {
  // use clocks
  auto now = sysclock::now();
  auto time = sysclock::to_time_t(now);
  return ::ctime(&time);
}

// // use C++11 function syntax
auto callback () -> void {
  std::cout << "thread started at " << now() << std::endl;

  std::this_thread::sleep_for(std::chrono::milliseconds(5000));

  std::cout << "thread finished at " << now() << std::endl;
};


int main (int, char*[]) {
  auto&& start = now();

  std::cout << "program started at " << start << std::endl;

  // use unordered map and initializer list
  std::unordered_map<std::string, std::string> values = {
    { "Hello", "World" }
  };

  // use auto and range iterator syntax
  for (auto const& it : values) {
    std::cout << it.first << " " << it.second << std::endl;
  }

  // use std::thread
  std::thread t(callback);
  t.join();

  std::cout << "program finished at " << now() << std::endl;
  return 0;
}
