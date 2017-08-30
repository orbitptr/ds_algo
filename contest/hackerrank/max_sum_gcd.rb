#!/bin/ruby

def maximumGcdAndSum(a, b)
	puts "before sorting"
    puts a.join(' ')
    puts b.join(' ')
	puts "\nafter sorting"
    a=a.sort.reverse
    b=b.sort.reverse
    puts a.join(' ')
    puts b.join(' ')
end

# n = gets.strip.to_i
# a = gets.strip
# a = a.split(' ').map(&:to_i)
# b = gets.strip
# b = b.split(' ').map(&:to_i)
a = ['8','4','3','2','1']
b = ['12','8','5','3','2']
res = maximumGcdAndSum(a, b)
puts res
