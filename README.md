OpenVirus [![Build Status](https://travis-ci.org/jaredsburrows/open-virus.svg?branch=master)](https://travis-ci.org/jaredsburrows/open-virus)
=========

**Open Source Virus Development**

Most viruses are captured in the wild and disassembled or sold from developer to developer. This repository is dedicated to demonstrate the basic functionality of visuses such as sending/receving information, loading modules and allowing reverse backdoor connections.

**Coming Soon:**
- Module Loader
- 32bit and 64bit compatible builds

### Commmand and Control Server - PHP
- Basic PHP script that accepts parameters and saves data
- Logging

### Server (virus) - C++
- Sends basic data back to Command and Constrol Server

### Client (reverse shell) - C
- Specify IP and Port to connect back to infected machine

### Setup

License
=========

    Copyright (C) 2015 OpenVirus by Jared Burrows
   
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
