# Paramedic

An in-memory shell drop executor.

# Usage

	scp paramedic user@machine:/home/user
	</bin/to/exec ssh user@machine /home/user/paramedic

`/bin/to/exec` will then be executed on the remote machine, given they are both compiled for the same architecture.

# DISCLAIMER

This has only been tested in **amd64**.
