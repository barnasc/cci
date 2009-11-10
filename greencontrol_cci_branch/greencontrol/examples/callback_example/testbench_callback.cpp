//   GreenControl framework
//
// LICENSETEXT
//
//   Copyright (C) 2007 : GreenSocs Ltd
// 	 http://www.greensocs.com/ , email: info@greensocs.com
//
//   Developed by :
//   
//   Christian Schroeder <schroeder@eis.cs.tu-bs.de>,
//   Wolfgang Klingauf <klingauf@eis.cs.tu-bs.de>
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

// SystemC library
#include <systemc>

/*
   Callback and notify tests:
    - Module ParameterOwnerModule owns some parameters
    - Module ObserverModule has some callback functions that are registered to the parameters
    - Module ParamManipulateModule changes the parameter values that should be observed by the MyIP2
 */

#include "callb_globals.h"

// GreenConfig
#include "greencontrol/config.h" 

#include "ParameterOwnerModule.h"
#include "ObserverModule.h"
#include "ParamManipulateModule.h"

/// Testbench for the example GreenConfig
int sc_main(int argc, char *argv[]) {
  
  /// GreenControl Core instance
  gs::ctr::GC_Core       core("ControlCore");

  // GreenConfig Plugin
  gs::cnf::ConfigDatabase cnfdatabase("ConfigDatabase");
  gs::cnf::ConfigPlugin configPlugin("ConfigPlugin", &cnfdatabase);

  ParameterOwnerModule  owner      ("Owner");
  ObserverModule        observer   ("Observer");
  ParamManipulateModule manipulator("Manipulator");

  sc_core::sc_start();
  
  return EXIT_SUCCESS; 
  
}