#!/usr/bin/env python3
"""
Script to convert single-line comments to proper multi-line /** */ format
for function documentation in cstring.cpp
"""

import re

def fix_comments(filepath):
    with open(filepath, 'r', encoding='utf-8') as f:
        content = f.read()
    
    # Pattern to match single-line comments before functions
    # Matches: // Comment\nvoid/int/float functionName(
    pattern = r'// ([^\n]+)\n((?:void|int|float|char) \w+\([^)]*\))'
    
    def replace_comment(match):
        comment = match.group(1)
        func_sig = match.group(2)
        
        # Create proper multi-line comment
        return f'/**\n * {comment}\n */\n{func_sig}'
    
    # Replace all single-line comments
    content = re.sub(pattern, replace_comment, content)
    
    # Write back
    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(content)
    
    print("Comments fixed successfully!")

if __name__ == '__main__':
    fix_comments(r'd:\programs\header_files\headerfiles\cstring\cstring.cpp')
