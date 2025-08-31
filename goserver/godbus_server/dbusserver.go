package godbusserver

import (
	"errors"
	"fmt"

	"github.com/godbus/dbus"
)

type Server struct{}

func (g *Server) Hello(name string) (string, *dbus.Error) {
	if name == "" {
		return "", dbus.MakeFailedError(errors.New("empty name"))
	}
	return fmt.Sprintf("Hi! %v", name), nil

}

func Init() error {
	conn, _err := dbus.SessionBus()

	if _err != nil {
		return _err
	}

	reply, _err := conn.RequestName("example.service", dbus.NameFlagDoNotQueue)
	if _err != nil {
		return _err
	}

	if reply != dbus.RequestNameReplyPrimaryOwner {
		return fmt.Errorf("name already taken")
	}

	fmt.Println("Connected to session bus!")

	_err = conn.Export(&Server{}, "/example/service", "example.service")

	if _err != nil {
		return _err
	}

	select {}
}
