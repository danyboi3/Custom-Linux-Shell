NAME = project1

SRC = project1.cpp


all: $(NAME)

$(NAME):
		g++ -o $(NAME) $(SRC)

clean :
	/bin/rm -f *.o project1

fclean:
	/bin/rm -f $(NAME)
