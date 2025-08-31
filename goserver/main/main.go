package main

import (
	godbusserver "esloth/awsS3"
	"log"
)

func main() {

	_err := godbusserver.Init()
	if _err != nil {
		log.Fatal(_err)
	}
}
