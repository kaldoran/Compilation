#!/bin/perl
     
# les noms dans le tableau sont ceux des commentaires a coté des defines. Si vous les changer pensez a changer la valeur dans le .h
open(FILE,"<./INC/syntax_tree.h") or die "POTATOES !";
print "char *node_name[] = {";
while (<FILE>) {
	chomp $_;
     print "\"$1\","if($_ =~  m/#define\s+AT_[A-Z_]*\s+[0-9]+\s*\/\/([a-zA-Z ]*)/);
}
print "\b};";
close (FILE);


