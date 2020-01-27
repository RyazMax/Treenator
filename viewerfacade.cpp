#include "viewerfacade.h"

void ViewerFacade::execute_command(std::shared_ptr<BaseCommand> command)
{
    command->execute(_mediator);
}
