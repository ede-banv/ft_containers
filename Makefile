NAME = ft_containers_test

SRCS = main.cpp

FTTEST = ft.test.txt

STDTEST = std.test.txt

DIFFTEST = diff.test

# OBJECTS = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# CXXFLAGS += -g3 -fsanitize=address

all : $(NAME)

$(NAME) : $(SRCS)

	${CXX} ${CXXFLAGS} -DTESTED_NAMESPACE=ft -o ${NAME} $(SRCS)
	./${NAME} > ${FTTEST}
	${CXX} ${CXXFLAGS} -DTESTED_NAMESPACE=std -o ${NAME} $(SRCS)
	./${NAME} > ${STDTEST}
	diff ${FTTEST} ${STDTEST} > ${DIFFTEST} || true

clean :
	rm -f $(OBJECTS) ${FTTEST} ${STDTEST} ${DIFFTEST}

fclean : clean
	rm -f $(NAME)

re : fclean all