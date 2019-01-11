import Data.Char

main = do
	line <- getLine
	let n:m:a:xs = getInts 3 line
	print $ (ceil n a)*(ceil m a)

ceil :: Integer -> Integer -> Integer

ceil x y = div (x - 1 + y) y

getInts :: Int -> String -> [Integer]

getInts 0 _ = []
getInts _ [] = []
getInts x str = map stringToInt $ take x $ words str

stringToInt :: String -> Integer

stringToInt str = read str :: Integer
