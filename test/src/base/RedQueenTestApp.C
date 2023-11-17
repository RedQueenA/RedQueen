//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "RedQueenTestApp.h"
#include "RedQueenApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
RedQueenTestApp::validParams()
{
  InputParameters params = RedQueenApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

RedQueenTestApp::RedQueenTestApp(InputParameters parameters) : MooseApp(parameters)
{
  RedQueenTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

RedQueenTestApp::~RedQueenTestApp() {}

void
RedQueenTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  RedQueenApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"RedQueenTestApp"});
    Registry::registerActionsTo(af, {"RedQueenTestApp"});
  }
}

void
RedQueenTestApp::registerApps()
{
  registerApp(RedQueenApp);
  registerApp(RedQueenTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
RedQueenTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  RedQueenTestApp::registerAll(f, af, s);
}
extern "C" void
RedQueenTestApp__registerApps()
{
  RedQueenTestApp::registerApps();
}
