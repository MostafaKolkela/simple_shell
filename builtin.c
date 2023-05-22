#include "shell.h"


/**

 * _myexit - exits the shell

 * @info: Struefhvbjd vms mvsd mnbkv sdn vbjcsvn,dsbvjbf

 * constant functioncsdjbbcvjhd\vbsdkv

 * Return: exits with a given exit status

 * (0) if info.argv[0] != "exit"

 */

int _myexit(info_t *info)

{

        int exit;


        if (info->argv[1]) /* If there is an exit arguement */

        {

                exit = _erratoi(info->argv[1]);

                if (exit == -1)

                {

                        info->status = 2;

                        print_error(info, "Illegal number: ");

                        _eputs(info->argv[1]);

                        _eputchar('\n');

                        return (1);

                }

                info->err_num = _erratoi(info->argv[1]);

                return (-2);

        }

        info->err_num = -1;

        return (-2);

}


/**

 * _mycd - changes the current dirxectory of the process

 * @info: Structure containing potential arguments. Used to maintain

 * constant function prototype.

 * Return: Always 0

 */

int _mycd(info_t *info)

{

        char *s, *dirx, buffer[1024];

        int chdirx_ret;


        s = getcwd(buffer, 1024);

        if (!s)

                _puts("TODO: >>getcwd failure emsg here<<\n");

        if (!info->argv[1])

        {

                dirx = _getenv(info, "HOME=");

                if (!dirx)

                        chdirx_ret = /* TODO: what should this be? */

                                chdirx((dirx = _getenv(info, "PWD=")) ? dirx : "/");

                else

                        chdirx_ret = chdirx(dirx);

        }

        else if (_strcmp(info->argv[1], "-") == 0)

        {

                if (!_getenv(info, "OLDPWD="))

                {

                        _puts(s);

                        _putchar('\n');

                        return (1);

                }

                _puts(_getenv(info, "OLDPWD=")), _putchar('\n');

                chdirx_ret = /* TODO: what should this be? */

                        chdirx((dirx = _getenv(info, "OLDPWD=")) ? dirx : "/");

        }

        else

                chdirx_ret = chdirx(info->argv[1]);

        if (chdirx_ret == -1)

        {

                print_error(info, "can't cd to ");

                _eputs(info->argv[1]), _eputchar('\n');

        }

        else

        {

                _setenv(info, "OLDPWD", _getenv(info, "PWD="));

                _setenv(info, "PWD", getcwd(buffer, 1024));

        }

        return (0);

}


/**

 * _myhelp - changes the current dirxectory of the process

 * @info: Structure containing potential arguments. Used to maintain

 * constant function prototype.

 * Return: Always 0

 */

int _myhelp(info_t *info)

{

        char **arg_array;


        arg_array = info->argv;

        _puts("help call works. Function not yet implemented \n");

        if (0)

                _puts(*arg_array); /* temp att_unused workaround */

        return (0);

}


