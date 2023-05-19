################# Perl program for calculating Software power ####################
open(file,"$ARGV[0]")||die("Cannot open the file\n");
open(file1,">cost")||die("Cannot open the file\n");
$cost=0;
while($line = <file>){
	if($line=~/pushl/){
		$cost=$cost+1;
	}
	elsif($line=~/popl/){
		$cost=$cost+1;
	}
	elsif($line=~/movl/){
                $cost=$cost+1;
        }
	elsif($line=~/andl/){
                $cost=$cost+1;
        }
	elsif($line=~/call/){
                $cost=$cost+8;
        }
	elsif($line=~/addl/){
                $cost=$cost+2;
        }
	elsif($line=~/cmpl/){
                $cost=$cost+1;
        }
	elsif($line=~/jle/){
                $cost=$cost+10;
        }
	elsif($line=~/jmp/){
                $cost=$cost+10;
        }
	elsif($line=~/jge/){
                $cost=$cost+10;
        }
	elsif($line=~/movb/){
                $cost=$cost+2;
        }
	elsif($line=~/leal/){
                $cost=$cost+1;
        }
	elsif($line=~/movzbll/){
                $cost=$cost+1;
        }
	elsif($line=~/leave/){
                $cost=$cost+1;
        }
	else{}
}
print file1 "$cost\n";
	












