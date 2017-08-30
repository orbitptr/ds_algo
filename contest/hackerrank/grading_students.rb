#!/bin/ruby
require 'pp'


def roundoff(grade)
	if grade>37
		remainder = grade%5
		if remainder>3
			return (grade+(5-remainder))
		end
	end
	return grade	
end

n=gets.strip.to_i
grades = Array.new(n)
for index in (0..n-1)
	temp = gets.strip.to_i
	puts temp
end