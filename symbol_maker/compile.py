with open('symbol_maker.csv', 'r') as f:
    raw = f.readlines()[1:]

glyphs = []
glyph_name = "none"
while glyph_name != "\n":
    glyph_rows = []
    for i in range(8):
        if i == 0:
            glyph_name = raw[0].split(',')[-1]

        line = raw[i].split(',')
        binline = 'B'
        for cell in range(8):
            if line[cell] == '':
                binline += '0'
            else:
                binline += '1'
        glyph_rows.append(binline)

    glyphs.append((glyph_name.strip('\n'), glyph_rows))

    raw = raw[8:]

out = ""
def_row = '{"@%s@", {%s}},\n'
for g in glyphs:
    out = out + def_row % (g[0], ",".join(g[1]))

print(out)
