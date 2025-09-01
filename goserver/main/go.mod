module esloth/main

go 1.25.0

replace esloth/goserver => ../godbus_server

require esloth/goserver v0.0.0

require github.com/godbus/dbus v4.1.0+incompatible // indirect
