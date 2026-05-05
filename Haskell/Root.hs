import Text.Printf

main :: IO ()
main = do
    putStrLn"Enter a:"
    a <- readLn :: IO Double
    putStrLn"Enter b:"
    b <- readLn :: IO Double
    putStrLn"Enter c:"
    c <- readLn :: IO Double

    let d = b^2 - 4*a*c
    if d > 0 then
        let r1 = (-b + sqrt d) / (2*a)
            r2 = (-b - sqrt d) / (2*a)
        putStrLn "Roots are real and distinct:"
        printf "Roots: %.2f and %.2f\n" r1 r2

    else if d == 0 then
        let r = -b / (2*a)
        putStrLn"Roots are real and equal:"
        printf"Root: %.2f\n" r

    else
        let realPart = -b / (2*a)
            imagPart = sqrt (-d) / (2*a)
        putStrLn "Roots are complex conjugates:"
        printf "Roots1 %.2f + %.2fi\n" realPart imagPart 
        printf "Root2 %.2f - %.2fi\n" realPart imagPart
