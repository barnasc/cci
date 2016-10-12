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
 *  @file     main.cpp
 *  @brief    This implementation assigns initial values to a list of cci-parameters
 *            (without any knowledge of them being present in the model) and then
 *            instantiates the 'parameter_owner' and 'parameter_configurator' modules
 *  @author   P V S Phaneendra, CircuitSutra Technologies   <pvs@circuitsutra.com>
 *  @date     21st July, 2011 (Thursday)
 */

#include <cci_configuration>
#include <systemc.h>
#include <cassert>
#include <string>

#include "ex18_cci_configFile_Tool.h"
#include "ex18_parameter_owner.h"
#include "ex18_parameter_configurator.h"

/**
 *  @fn     int sc_main(int sc_argc, char* sc_argv[])
 *  @brief  Here, a reference of the global broker is taken with the help of
 *          the originator information and then initial values are assigned to
 *          a list of cci-parameters.
 *  @param  sc_argc The number of input arguments
 *  @param  sc_argv The list of input arguments
 *  @return An integer denoting the return status of execution.
 */
int sc_main(int sc_argc, char* sc_argv[]) {
  cci::ex18_cci_configFile_Tool configTool("configFileTool");
  configTool.config("./ex18_Superset_Parameter_Value_Specification/Configuration_File.txt");

#if 0
  // In case, if user doesn't want to use the reading from configuration file
  // approach, here is an alternative that assigns initial values to the
  // cci-parameters

  // Declare cci-originator instance in order to retrieve a reference of the
  // global broker
  cci::cci_originator sc_main_originator("sc_main_originator");

  // Get reference/handle of the default global broker
  cci::cci_broker_if* myMainBrokerIF =
      &cci::cci_broker_manager::get_current_broker(sc_main_originator);

  // Assert if the returned broker handle is NULL
  assert(myMainBrokerIF != NULL && "SC_MAIN_BROKER_IF handle is returned NULL");

  SC_REPORT_INFO("sc_main", "[MAIN] : Set initial value to 'integer type"
                 " parameter'");
  myMainBrokerIF->set_initial_cci_value("param_owner.int_param",
                                        cci::cci_value::from_json("10"));

  SC_REPORT_INFO("sc_main", "[MAIN] : Set initial value to 'float type"
                 " parameter'");
  myMainBrokerIF->set_initial_cci_value("param_owner.float_param",
                                        cci::cci_value::from_json("11.11"));

  SC_REPORT_INFO("sc_main", "[MAIN] : Set initial value to 'string type"
                 " parameter'");
  myMainBrokerIF->set_initial_cci_value("param_owner.string_param",
    cci::cci_value::from_json("Used_parameter"));

  SC_REPORT_INFO("sc_main", "[MAIN] : Set initial value to 'double type"
                 " parameter'");
  myMainBrokerIF->set_initial_cci_value("param_owner.double_param",
    cci::cci_value::from_json("100.123456789"));
#endif

  // Instatiation of 'parameter_owner' and 'parameter_configurator' modules
  ex18_parameter_owner param_owner("param_owner");
  ex18_parameter_configurator param_cfgr("param_cfgr");

  // BEOE, EOE and simulation phases advance from here
  sc_start(10.0, SC_NS);

  return EXIT_SUCCESS;
}
// sc_main
