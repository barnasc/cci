/*******************************************************************************
 *   The following code is derived, directly or indirectly, from the SystemC
 *   source code Copyright (c) 1996-2010 by all Contributors.
 *   All Rights reserved.
 *
 *   The contents of this file are subject to the restrictions and limitations
 *   set forth in the SystemC Open Source License Version 2.2.0 (the "License");
 *   One may not use this file except in compliance with such restrictions and
 *   limitations.  One may obtain instructions on how to receive a copy of the
 *   License at http://www.systemc.org/.  Software distributed by Contributors
 *   under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
 *   ANY KIND, either express or implied. See the License for the specific
 *   language governing rights and limitations under the License.
 *******************************************************************************/

/*!
 * \file    parameter_owner.h
 * \brief   This file defines the OWNER module's functionality.
 *          This file defines a 'PARAMETER_OWNER' sc_module which, in turn,
 *          'int-type' & 'string-type'cci-parameters with default values
 * \author  P V S Phaneendra, CircuitSutra Technologies   <pvs@circuitsutra.com>
 * \date    12th September, 2011 (Monday)
 */
#ifndef EXAMPLES_EX07_PARAMETER_INFORMATION_EX07_PARAMETER_OWNER_H_
#define EXAMPLES_EX07_PARAMETER_INFORMATION_EX07_PARAMETER_OWNER_H_

#include <cci>
#include <string>
#include "xreport.hpp"

/// The parameter owner initializes various CCI-based parameters
SC_MODULE(ex07_parameter_owner) {
 public:
  SC_CTOR(ex07_parameter_owner)
  // Assign initial value to mutable_int_param
      : int_param("mutable_int_param", 0),
        // Assign a name to the string param (Default is not assigned)
        string_param("mutable_string_param", "Default_Value") {
    SC_THREAD(run_thread);

    XREPORT("Prior to " << sc_core::sc_time_stamp()
            << "\tdemonstrating 'is_initial_value' API");

    XREPORT("[OWNER] : Parameter : " << int_param.get_name() << "\tValue : "
            << int_param.get());

    XREPORT("Is initial value ?\t" << std::boolalpha
            << int_param.is_initial_value());

    XREPORT("Prior to " << sc_core::sc_time_stamp()
            << "\tdemonstrating 'get_default_value()'");
    XREPORT("[OWNER -> Retrieve] : Parameter name  : " << int_param.get_name());

    // Setting parameter value using 'cci_value' not implemented
    // Used something like : int_param = 1; (see code within the SC_THREAD)

    /// Query default value of a parameter using 'get_default_type()' API
    XREPORT("[OWNER -> Retrieve] : Using 'get_default_value()' : "
            << int_param.get_default_value());

    /// Set Documentation - This gives the meta-data about the parameter
    XREPORT("[OWNER -> Set] : Param documentation - 'This is a mutable"
            " type integer parameter'");
    const std::string init_doc = "This is a mutable type integer parameter";
    int_param.set_documentation(init_doc);
  }

  void run_thread() {
    while (1) {
      wait(1.0, sc_core::SC_NS);

      // Override the default value
      XREPORT("@ " << sc_core::sc_time_stamp());
      XREPORT("[OWNER -> Set] : Overriding default value of "
              << int_param.get_name() << " to 1");

      /// Setting value to the integer type parameter
      int_param = 1;

      wait(17.0, sc_core::SC_NS);

      XREPORT("@ " << sc_core::sc_time_stamp()
              << " demonstrating 'set_value_invalid()'");
      XREPORT("[OWNER -> Set] : " << int_param.get_name() << " value invalid.");

      /// Set the cci parameter to invalid state using
      /// 'set_invalid_state()' API
      int_param.set_invalid_value();

      /// Query a cci parameter value validity using
      /// 'is_invalid_value()' API
      if (int_param.is_invalid_value()) {
        XREPORT("[OWNER] : Is Invalid Value ? " << "\tReturned Status : "
                << std::boolalpha << int_param.is_invalid_value());
        XREPORT("[OWNER -> Retrieve] : " << int_param.get_name() << "\tValue : "
                << int_param.get());
      } else {
        XREPORT("[OWNER] : Is Invalid Value ? " << "\tReturned Status : "
                << std::boolalpha << int_param.is_invalid_value());
        XREPORT("[OWNER -> Retrieve] : " << int_param.get_name() << "\tValue : "
                << int_param.get());
      }

      wait(8.0, sc_core::SC_NS);

      XREPORT("@ " << sc_core::sc_time_stamp()
              << "\tdemonstrating setting values by OWNER using cci_value");
      XREPORT("[OWNER -> Set] : New String Value : 'String_Value_Set_by_OWNER");

      cci::cnf::cci_value str_value("String_Value_Set_by_OWNER");
      string_param.set_value(str_value);

      wait(2.0, sc_core::SC_NS);

      XREPORT("@ " << sc_core::sc_time_stamp()
              << "\tdemonstrating retrieving values by OWNER using cci_value");

      cci::cnf::cci_value rec_str_value = string_param.get_value();
      std::string recv_str = rec_str_value.get_string();

      XREPORT("[OWNER -> Retrieve] : Receive str_value using 'cci_value' : "
              << recv_str);

      wait(10.0, sc_core::SC_NS);
    }
  }

 private:
  // CCI parameters declarations
  cci::cnf::cci_param<int> int_param;
  cci::cnf::cci_param<std::string> string_param;
};
// ex07_parameter_owner

#endif  // EXAMPLES_EX07_PARAMETER_INFORMATION_EX07_PARAMETER_OWNER_H_