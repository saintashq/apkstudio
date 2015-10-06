#include "constants.h"
#include "runner.h"

AS_NAMESPACE_START

Runner* Runner::_self = nullptr;

Runner::Runner(QObject *p)
    : QObject(p), _pool(new QThreadPool(this))
{
    _pool->setMaxThreadCount(THREADS_MAX);
}

void Runner::add(Runnable *r)
{
    _connections << connect(r, &Runnable::runnableStopped, r, &Runnable::deleteLater, Qt::QueuedConnection);
    _pool->start(r);
}

Runner *Runner::get()
{
    if (!_self)
    {
        _self = new Runner();
    }
    return _self;
}

Runner::~Runner()
{
    AS_CONNECTIONS_DISCONNECT
}

AS_NAMESPACE_END
