import QtQuick 2.0
import B2Qt.Wifi 1.0

Item {

    WifiConfiguration {
        id: localConfig
        ssid: "bus-station-wifi"
        passphrase: "mypassword"
        protocol: "WPA2"
    }

    Connections {
        target: WifiManager
        onBackendStateChanged: {
            if (WifiManager.backendState === WifiManager.Running)
                WifiManager.connect(localConfig)
        }
        onNetworkStateChanged: {
            if (WifiManager.networkState === WifiManager.Connected)
                print("successfully connected to: " + WifiManager.currentSSID)
        }
    }

    Component.onCompleted: {
        if (WifiManager.backendState === WifiManager.Running) {
            WifiManager.connect(localConfig)
        } else {
            // starts initialization of wifi backend
            WifiManager.start()
        }
    }
}


