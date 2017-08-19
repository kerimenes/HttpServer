#include "erpdataaccess.h"

ErpDataAccess::ErpDataAccess(int port, QObject *parent)
  : SimpleHttpServer(port, parent)
{

}

