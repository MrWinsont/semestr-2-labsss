cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME s2lab6)				 # задать константу с именем проекта		 
project("${PROJECT_NAME}")			 # имя проекта	


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

			 # указываем, где искать файлы заголовков

add_executable("${PROJECT_NAME}" logger.cpp
				 log.hpp
			         log.cpp)
								 	# добавить исполняемый файл
								 
#file(COPY Loger.txt DESTINATION "/")    # скопировать файл text.txt в корневую папку проекта