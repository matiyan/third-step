require "numo/narray"

puts "笑介くんのクラス20人のテストの点数は,理科が"


science=Numo::DFloat[65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 2, 58.5, 46, 42, 78, 62, 84, 70]

science.each{|i|print i.to_s+" "}
puts "英語が"

english=Numo::DFloat[44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84]

english.each{|i|print i.to_s+" "}

puts "でした."

puts "理科:"
puts "平均点="+science.mean.to_s
puts "標準偏差="+science.stddev.to_s
puts "合計="+science.sum.to_s
puts "英語:"
puts "平均点="+english.mean.to_s
puts "標準偏差="+english.stddev.to_s
puts "合計="+english.sum.to_s

print "理科の偏差値\n"
science.each{|i|print (50+10*((i-science.mean)/science.stddev)).to_s+" "}
puts "英語の偏差値\n"
english.each{|i|print (50+10*((i-english.mean)/english.stddev)).to_s+" "}

print "理科のソート\n"
p science.sort{|a, b| b <=> a}.reverse

print "英語のソート\n"
p english.sort{|a, b| b <=> a}.reverse


