<?php

    $n = readline("I'd like an integer, please: ");

    if ($n > 0)
    {
        print("you picked a positive number!\n");
    }
    else if ($n == 0)
    {
        print("You picked zero!\n");
    }
    else
    {
        print("You picked a negative number!\n");
    }

?>