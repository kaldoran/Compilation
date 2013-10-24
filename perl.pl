#!/bin/perl
     
open(FILE,"<syntax_tree.h") or die "POTATOES !";
print "char *node_name[] = {";
while (<FILE>) {
	chomp $_;
     print "\"$1\","if($_ =~  m/#define\s+AT_[A-Z_]*\s+[0-9]+\s*\/\/([a-zA-Z ]*)/);
}
print "};";
close (FILE);


