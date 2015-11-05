require 'json'
require 'rexml/document'


class WordCounter


	class Result
		attr_accessor :marks, :words
			
		def to_csv 
		end
		
		def to_json
			content_hash["marks"] = sumofmarks
			content_hash["words"] = words_hash
			return content_hash
		end
		
		def to_xml
			file_xml = REXML::Document.new('')
			word_count = file_xml.add_element('word-count')
			marks_xml = word_count.add_element('marks').add_text(sumofmarks.to_s)
			words_xml = word_count.add_element('words')
			words_hash.each do |key, value|
				words_xml.add_element('word').add_text(key).add_attribute('count', value.to_s)
			end
			return file_xml
		
		end
	end
	
	def parse_file
	end

end

result = WOrdCounter::Result.new

result.to_csv
result.to_xml

counter = WordCounter.new
result2 = counter.parse 


