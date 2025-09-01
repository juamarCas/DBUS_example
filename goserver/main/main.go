package main

import (
	godbusserver "esloth/goserver"
	"log"
)

func main() {

	_err := godbusserver.Init()
	if _err != nil {
		log.Fatal(_err)
	}
}
