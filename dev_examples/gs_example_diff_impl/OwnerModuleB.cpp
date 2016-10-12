/*****************************************************************************

  Licensed to Accellera Systems Initiative Inc. (Accellera) under one or
  more contributor license agreements.  See the NOTICE file distributed
  with this work for additional information regarding copyright ownership.
  Accellera licenses this file to you under the Apache License, Version 2.0
  (the "License"); you may not use this file except in compliance with the
  License.  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
  implied.  See the License for the specific language governing
  permissions and limitations under the License.

 ****************************************************************************/

/**
 * @file   OwnerModuleB.cpp
 * @author Christian Schroeder, GreenSocs
 */

#include "OwnerModuleB.h"
#include <systemc.h>
//#include "cci_params_b.h" // THIS IS THE DIFFERENT PARAMETER IMPLEMENTATION!!!

void OwnerModuleB::main_action() {

  std::cout << "----------------------------" << std::endl;

  // get the broker which is responsible for this module
  cci::cci_broker_if* mBroker = &cci::cci_broker_manager::get_current_broker(cci::cci_originator(*this));
  assert(mBroker != NULL && "get_cnf_broker_instance returned is NULL");

  
  std::cout << "----------------------------" << std::endl;

}
