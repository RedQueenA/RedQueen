#include "RedQueenApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
RedQueenApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

RedQueenApp::RedQueenApp(InputParameters parameters) : MooseApp(parameters)
{
  RedQueenApp::registerAll(_factory, _action_factory, _syntax);
}

RedQueenApp::~RedQueenApp() {}

void 
RedQueenApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<RedQueenApp>(f, af, s);
  Registry::registerObjectsTo(f, {"RedQueenApp"});
  Registry::registerActionsTo(af, {"RedQueenApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
RedQueenApp::registerApps()
{
  registerApp(RedQueenApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
RedQueenApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  RedQueenApp::registerAll(f, af, s);
}
extern "C" void
RedQueenApp__registerApps()
{
  RedQueenApp::registerApps();
}
