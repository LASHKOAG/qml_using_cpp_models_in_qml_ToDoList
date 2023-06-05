import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

//16
import ToDo 1.0

//62 add ColumnLayout
ColumnLayout {
    Frame {
        ListView {
            implicitWidth: 250
            implicitHeight: 250
            clip: true

            //1
            //model: 100

            //2
            //        model: ListModel {
            //            //3
            //            ListElement {
            //                //done: - role; description: -role
            //                done: true
            //                description: "Wash the car"
            //            }
            //            ListElement {
            //                //done: - role; description: -role
            //                done: false
            //                description: "Fix the sink"
            //            }
            //        }

            //17 change model to model cpp
            //еще невозможно изменить через графический интерфейс что либо
            //необходимо реализовать способ хранения новых изменений в бэкэнд
            model: ToDoModel {
                //61 and run
                list: toDoList
            }


            delegate: RowLayout {
                width: parent.width

                CheckBox {
                    //4
                    checked: model.done
                    //run program - TextField empty, need to add text

                    //6 чтобы изменения в квадратике сохранились в модели
                    onClicked: model.done = checked
                }
                TextField {
                    //чтобы поле ввода занимала максимальное пространство
                    Layout.fillWidth: true
                    //5
                    text: model.description
                    //7 чтобы сохранить изменения текста в модели. Отработает либо после Enter, либо когда поменяется фокус
                    onEditingFinished: model.description = text

                }
            }
        }
    }

    //63
    RowLayout {
        Button {
            text: qsTr("Add new item")
        }
        Button {
            text: qsTr("Remove completed")
        }
    }

}

//8 next step add cpp model. see README.md
