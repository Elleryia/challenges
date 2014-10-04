#Sample code to read in test cases:
use strict;
use warnings;

sub isprime
{
    my $num = shift;
    if ($num < 2) {return 0;}
    if ($num == 2) {return 1;}
    else 
    {   
        for (my $j = 2; $j <= sqrt($num); $j++) 
        {
            if ($num % $j == 0) {return 0;}
        }
    }
    return 1;
}

my $count = 0;
my $sum = 0;
my $n = 0;

while ($count < 1000)
{
    if(isprime($n))
    {
        $count++;
        $sum = $sum + $n;
    }
    $n++;
}
print $sum."\n";