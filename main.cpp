#include <QGuiApplication>
#include <QQmlApplicationEngine>

//14
#include "todomodel.h"

//39
#include <QQmlContext>
//40
#include "todolist.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //15
    qmlRegisterType<ToDoModel>("ToDo", 1, 0, "ToDoModel");

    //41
    ToDoList toDoList;

    QQmlApplicationEngine engine;

    //42 доступен в любом файле qml
    engine.rootContext()->setContextProperty(QStringLiteral("toDoList"), &toDoList);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
