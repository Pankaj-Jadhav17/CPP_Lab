module Main where
import Data.Ratio (numerator, denominator)

toMixedRational :: Double -> (Integer, Integer, Integer)
toMixedRational x =
    let r        = toRational x
        (i, f)   = properFraction r
        a        = numerator f
        b        = denominator f
    in (i, a, b)

display :: Double -> String
display x
    | x <= 0    = "Error: Please enter a positive number!"
    | a == 0    = "Result: " ++ show i ++ " (whole number, no fraction)"
    | otherwise = "Result: " ++ show i ++ " + " ++ show a ++ "/" ++ show b ++
                  "3\n  Where I=" ++ show i ++
                  ", A=" ++ show a ++
                  ", B=" ++ show b ++
                  "\n  A and B are co-prime (GCD = 1)"
    where
        (i, a, b) = toMixedRational x

main :: IO ()
main = do
    putStrLn "   Mixed Rational Representation       "
    putStrLn "   Format: I + A/B                     \n"
    putStrLn "Enter a positive number:"
    line <- getLine
    let x = read line :: Double
    putStrLn "---------------------------------------"
    putStrLn $ "Input Number : " ++ show x
    putStrLn (display x)
