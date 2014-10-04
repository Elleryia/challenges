#Sample code to read in test cases:
use strict;
use warnings;

sub isprime
{
    my $num = shift;
    if ($num < 2) {return 0;}
    if ($num == 2) {return 1;}
    else {for (my $j = 2; $j < sqrt($num); $j++) {if ($num % $j == 0) {return 0;}}}
    return 1;
}

for(my $i = 1000; $i > 0; $i--)
{
    if(($i eq reverse($i)) and (isprime($i))) 
    {
        print $i;
        last;
    }
}