#include "LocalMessages.h"
void LocalMessage::addClient(int socket)
{
    clients.insert(socket);
}
void LocalMessage::runRule()
{
    
}