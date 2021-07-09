
#########support vars start#####################
SRCS_DIR = srcs/
SRC_CHECK_DEAD = $(addprefix check_dead/, is_dead_or_fed.c \
	wait_till_dead_fed.c)
SRCS_CYCLE_PHILOSOPHER = $(addprefix cycle_philosopher/, cycle_philosopher.c \
	put_back_forks.c start_eating.c start_sleeping.c \
	start_thinking.c take_forks.c)
SRCS_ERROR = $(addprefix error/, error.c)
SRCS_MAIN = $(addprefix main/, philo_two.c)
SRCS_MODEL = $(addprefix model/, clean_model.c init_model.c \
	init_mutexes.c init_philos.c parse_sim_setups.c unblock_sems.c)
SRCS_PHILO_THREAD = $(addprefix philo_thread/, print.c \
	start_philosophers.c time.c join_threads.c)
SRCS_UTILS = $(addprefix utils/, utils.c)
#########support vars end#######################

NAME = philo_two

SRCS = $(addprefix $(SRCS_DIR), $(SRC_CHECK_DEAD) $(SRCS_CYCLE_PHILOSOPHER) \
	$(SRCS_ERROR) $(SRCS_MAIN) $(SRCS_MODEL) $(SRCS_PHILO_THREAD) \
	$(SRCS_UTILS))

HEADERS = $(addprefix $(SRCS_DIR), check_dead/check_dead.h \
	cycle_philosopher/cycle_philosopher_utils.h error/error.h model/model.h \
		philo_thread/philo_thread.h utils/utils.h)

HEADERS_DIRS = -Isrcs/check_dead -Isrcs/cycle_philosopher -Isrcs/error \
	-Isrcs/main -Isrcs/model -Isrcs/philo_thread -Isrcs/utils

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADERS_DIRS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug_c:
	$(CC) -g $(SRCS) -o $(NAME) 

run: debug_c
	./philo_two 5 800 200 200 3

remove_odd_objs:
	find . -name "*.o" -type f -delete