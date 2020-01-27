#ifndef VIEWERFACADE_H
#define VIEWERFACADE_H


#include "Commands/commands.h"
#include "mediator.h"

class ViewerFacade
{
public:
    ViewerFacade() = default;
    ~ViewerFacade() = default;

    void execute_command(std::shared_ptr<BaseCommand> command);

private:
    Mediator _mediator;
};

#endif // VIEWERFACADE_H
