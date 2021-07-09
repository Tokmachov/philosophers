#########support vars start#####################
SRCS_DIR = srcs/
SRC_CHECK_DEAD = $(addprefix check_dead/, check_if_philo_dead_or_fed.c)
SRCS_CYCLE_PHILOSOPHER = $(addprefix cycle_philosopher/, cycle_philosopher.c \
	put_back_forks.c start_eating.c start_sleeping.c \
	start_thinking.c take_forks.c)
SRCS_ERROR = $(addprefix error/, error.c)
SRCS_MAIN = $(addprefix main/, philo_three.c)
SRCS_MODEL = $(addprefix model/, clean_model.c init_model.c \
	init_sems.c init_philos.c parse_sim_setups.c)
SRCS_PHILO_PROCESS = $(addprefix philo_process/, print.c \
	start_philo_processes.c time.c)
SRCS_UTILS = $(addprefix utils/, utils.c)
#########support vars end#######################

NAME = philo_three

SRCS = $(addprefix $(SRCS_DIR), $(SRC_CHECK_DEAD) $(SRCS_CYCLE_PHILOSOPHER) \
	$(SRCS_ERROR) $(SRCS_MAIN) $(SRCS_MODEL) $(SRCS_PHILO_PROCESS) \
	$(SRCS_UTILS))

HEADERS = $(addprefix $(SRCS_DIR), check_dead/check_dead.h \
	cycle_philosopher/cycle_philosopher_utils.h error/error.h model/model.h \
	philo_process/philo_process.h utils/utils.h)

OBJS = $(SRCS:.c=.o)

HEADER_DIRS = -Isrcs/check_dead -Isrcs/cycle_philosopher -Isrcs/error \
	-Isrcs/main -Isrcs/model -Isrcs/philo_process -Isrcs/utils

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADER_DIRS) $< -o $@

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