perl -nlpe 's/[0-9A-F]{2} ?/chr(hex($&))/ieg'
