/****************************************************************************
 * This file is part of Fluid.
 *
 * Copyright (C) 2014-2016 Pier Luigi Fiorini
 *
 * Author(s):
 *    Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * $BEGIN_LICENSE:LGPL2.1+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

#include <QtQml/qqml.h>
#include <QtQml/QQmlExtensionPlugin>

#include "standardpaths.h"

static QObject *standardpathsProvider(QQmlEngine *engine, QJSEngine *jsEngine)
{
    Q_UNUSED(engine);
    Q_UNUSED(jsEngine);

    StandardPaths *paths = new StandardPaths();
    return paths;
}

class FluidCorePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
public:
    void registerTypes(const char *uri);
};

void FluidCorePlugin::registerTypes(const char *uri)
{
    Q_ASSERT(QByteArray("Fluid.Core") == QByteArray(uri));

    // @uri Fluid.Core
    qmlRegisterSingletonType<StandardPaths>(uri, 1, 0, "StandardPaths",
                                            standardpathsProvider);
}

#include "plugin.moc"
