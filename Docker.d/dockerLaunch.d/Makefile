

listall:
	@echo "  docker ps -a"

run_hello_w:
	@echo "  docker run hello-world"

run_ubuntu_bash:
	@echo "  docker run -it ubuntu bash"

list_images:
	@echo "  docker image ls"

say_howto_prune:
	@echo '  docker image prune <IMAGE ID>'

run_newest_trial:
	@echo '  docker run -it <IMAGE ID> bash'
	@echo '  ex.'
	@echo '  docker run -it 972fe421b9ca bash'

remove:
	@echo "  docker rm <NAME>"

stop:
	@echo "  docker stop <MY_CONTAINER>"

example_aaa_h:
	@/bin/echo -e  "  $$ docker ps -a"
	@/bin/echo     "  CONTAINER ID   IMAGE         COMMAND     CREATED         STATUS                      PORTS     NAMES"

stop_example:	example_aaa_h
	@/bin/echo     '  e249af77328e   ubuntu        "bash"      5 minutes ago   Up 5 minutes                          gracious_boyd'
	@/bin/echo     '  62cc21ffa502   hello-world   "/hello"    7 minutes ago   Exited (0) 7 minutes ago              stoic_perlman'
	@echo     ""
	@/bin/echo -e  "  $$ docker stop gracious_boyd"

rm_example:	example_aaa_h
	@/bin/echo -e '  7bf908fa51bb   hello-world   "/hello"   28 minutes ago   Exited (0) 28 minutes ago             ecstatic_dirac'
	@/bin/echo -e '   $$ docker rm ecstatic_dirac'
	@/bin/echo -e '  ecstatic_dirac'


# end.
