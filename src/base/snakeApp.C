#include "snakeApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<snakeApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

snakeApp::snakeApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  snakeApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  snakeApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  snakeApp::registerExecFlags(_factory);
}

snakeApp::~snakeApp() {}

void
snakeApp::registerApps()
{
  registerApp(snakeApp);
}

void
snakeApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"snakeApp"});
}

void
snakeApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"snakeApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
snakeApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
snakeApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
snakeApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
snakeApp__registerApps()
{
  snakeApp::registerApps();
}

extern "C" void
snakeApp__registerObjects(Factory & factory)
{
  snakeApp::registerObjects(factory);
}

extern "C" void
snakeApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  snakeApp::associateSyntax(syntax, action_factory);
}

extern "C" void
snakeApp__registerExecFlags(Factory & factory)
{
  snakeApp::registerExecFlags(factory);
}
