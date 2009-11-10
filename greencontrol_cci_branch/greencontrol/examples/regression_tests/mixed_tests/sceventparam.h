//   GreenControl framework
//
// LICENSETEXT
//
//   Copyright (C) 2009 : GreenSocs Ltd
// 	 http://www.greensocs.com/ , email: info@greensocs.com
//
//   Developed by :
//   
//   Christian Schroeder <schroeder@eis.cs.tu-bs.de>,
//     Technical University of Braunschweig, Dept. E.I.S.
//     http://www.eis.cs.tu-bs.de
//
//
//   This program is free software.
// 
//   If you have no applicable agreement with GreenSocs Ltd, this software
//   is licensed to you, and you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
// 
//   If you have a applicable agreement with GreenSocs Ltd, the terms of that
//   agreement prevail.
// 
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
// 
//   You should have received a copy of the GNU General Public License
//   along with this program; if not, write to the Free Software
//   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
//   02110-1301  USA 
// 
// ENDLICENSETEXT

// ////////////////////////////////////////////////////////////////////// //
// ///////// Regression tests for gs_param<sc_attribute<T> > //////////// //
// ////////////////////////////////////////////////////////////////////// //

#ifndef __SCEVENTPARAM_H__
#define __SCEVENTPARAM_H__

#include <systemc>

#include "greencontrol/config.h"


/// Test IP testing sc_attribute parameters
class Param_test_sc_event
: public sc_core::sc_module
{
  
public:
  
  GC_HAS_CALLBACKS();
  
  SC_HAS_PROCESS(Param_test_sc_event);
  
  /// Constructor
  Param_test_sc_event(sc_core::sc_module_name name)
  : sc_core::sc_module(name)
  , event_param("event_param")
  { 
    SC_THREAD(main_action);
  }
  
  /// Destructor
  ~Param_test_sc_event() {
    GC_UNREGISTER_CALLBACKS();
  }
  
  /// Main action to make tests with parameters.
  void main_action();
  
  /// Example parameter.
  gs::gs_param<sc_core::sc_event >           event_param;
  
};


#endif

