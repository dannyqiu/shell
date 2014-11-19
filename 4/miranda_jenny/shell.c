#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int i = 1;

void execute( char * args[] ) {
    int f;
    
    if ( !strcmp(args[0], "cd") ) {
        chdir( args[1] );
    }
    if ( !strcmp(args[0], "exit") ) {
        i = 0;
    }
    
    f = fork();
    if ( !f ) {
        execvp(args[0], args);
    }
    else {
        wait(&f);
    }
}

int main(){
    printf( "Welcome to the The Magic Conch Shell.\n" );
    
    char cwd[200];
    char input_str[100];
    
    while( i ) {
        getcwd( cwd, sizeof(cwd) );
        printf( "%s$ ", cwd );
        
        fgets( input_str, sizeof(input_str), stdin );
        char *temp = input_str; //strsep needs char*, not char[]
        char *raw_str = strsep(&temp, "\n"); //removes ending line break
        
        //strchr for ;
        char *split_cmds; //holds the piece separated off from raw_str (a cmd + arg string)
        char * cmds[10]; //cmd array
        int c = 0;
        
        while( split_cmds = strsep(&raw_str, ";") ) {
            cmds[c] = split_cmds;
            c++;
        }
        cmds[c] = 0;
        
        int x;
        for ( x = 0; cmds[x]; x++ ) {
            char *split_args; //holds the piece separated off from x
            char * args[10]; //arg array
            int a = 0;
            
            while( split_args = strsep(&x, " ") ) {
                args[a] = args;
                a++;
            }
            execute(args);
        }
    }
    return 0;
}


