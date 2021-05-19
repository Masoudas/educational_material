/**
 * This is just a reminder that we can freely add noise to matrix using the simple plus operator. This is 
 * because the plus operator goes as far as saturating values for us.
 * 
 * However, the constraint here is that both the noise and matrix must have the same type. If one has a type
 * that's different from the other, then we need an actuall loop.
 * 
 * What they do in the literiture is to generate the noise and just directly add it, but that always feels
 * wrong to me, because adding the noise like this several times causes saturation! Although physically
 * speaking, this is correct.
 */