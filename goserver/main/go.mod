module esloth/main

go 1.25.0

replace esloth/awsS3 => ../godbus_server

require esloth/awsS3 v0.0.0

require github.com/godbus/dbus v4.1.0+incompatible // indirect
