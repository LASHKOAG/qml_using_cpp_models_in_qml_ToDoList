import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Frame {
    ListView {
        implicitWidth: 250
        implicitHeight: 250
        clip: true

        //1
        //model: 100

        //2
        model: ListModel {
            //3
            ListElement {
                //done: - role; description: -role
                done: true
                description: "Wash the car"
            }
            ListElement {
                //done: - role; description: -role
                done: false
                description: "Fix the sink"
            }
        }

        delegate: RowLayout {
            width: parent.width

            CheckBox {
                //4
                checked: model.done
                //run program - TextField empty, need to add text
            }
            TextField {
                //чтобы поле ввода занимала максимальное пространство
                Layout.fillWidth: true
                //5
                text: model.description

            }
        }
    }
}
