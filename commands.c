#include "memory.h"
#include "text.h"
#include "commands.h"
#include "builtins.h"
#include "general.h"

/**
 * analyze - dfvjbkjdb dkjvbb jvjz jk voudvh
 *
 * @arguments: Comman dbkjbcjvbjkdv vkjb ddbf
 * @info: Gener kjfdvbjfbdf vbjdfvf,vldnf
 * @buff: Line re dkbfjbjdfvbjdfnvnsdvjk vk
 **/
void analyze(char **arguments, general_t *info, char *buff)
{
	char *cmd;
	int status;

	if (*arguments == NULL || arguments == NULL)
		return;

	cmd = arguments[0];
	info->command = cmd;
	if (check_builtin(info, arguments) == _TRUE)
		return;

	status = is_file(cmd);
	if (status == NON_PERMISSIONS)
	{
		info->status_code = 126;
		info->error_code = _CODE_EACCES;
		error(info);
		return;
	}

	if (status == 1)
	{
		execute(cmd, arguments, info, buff);
		return;
	}

	if (current_directory(cmd, arguments, buff, info) == _TRUE)
		return;

	info->value_path = which(cmd, info);
	if (info->value_path != NULL)
	{
		execute(info->value_path, arguments, info, buff);
		free_memory_p((void *) info->value_path);
		return;
	}

	info->status_code = 127;
	info->error_code = _CODE_CMD_NOT_EXISTS;
	error(info);
}
