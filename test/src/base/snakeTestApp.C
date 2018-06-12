//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "snakeTestApp.h"
#include "snakeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<snakeTestApp>()
{
  InputParameters params = validParams<snakeApp>();
  return params;
}

snakeTestApp::snakeTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  snakeApp::registerObjectDepends(_factory);
  snakeApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  snakeApp::associateSyntaxDepends(_syntax, _action_factory);
  snakeApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  snakeApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    snakeTestApp::registerObjects(_factory);
    snakeTestApp::associateSyntax(_syntax, _action_factory);
    snakeTestApp::registerExecFlags(_factory);
  }
}

snakeTestApp::~snakeTestApp() {}

void
snakeTestApp::registerApps()
{
  registerApp(snakeApp);
  registerApp(snakeTestApp);
}

void
snakeTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
snakeTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
snakeTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
snakeTestApp__registerApps()
{
  snakeTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
snakeTestApp__registerObjects(Factory & factory)
{
  snakeTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
snakeTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  snakeTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
snakeTestApp__registerExecFlags(Factory & factory)
{
  snakeTestApp::registerExecFlags(factory);
}
