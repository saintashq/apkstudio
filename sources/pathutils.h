#ifndef PATHUTILS_H
#define PATHUTILS_H

#include <QString>
#include "macros.h"

AS_NAMESPACE_START

class PathUtils
{
public:
    static QString combine(const QString &l, const QString &r);
    static QString find(const QString &exe);
    static QString temp(const QString &name, const QString &dir = QString());
};

AS_NAMESPACE_END

#endif // PATHUTILS_H
