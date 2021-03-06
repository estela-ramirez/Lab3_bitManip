tests = [{'description': 'PINA: 0x00 => PORB: 0x01',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
    'expected': [('PORTB',0x01)],
    },
    {'description': 'PINA: 0x01 => PORB: 0xa02',
    'steps': [ {'inputs': [('PINA',0x01)], 'iterations': 5 } ],
    'expected': [('PORTB',0x02)],
    },
    {'description': 'PINA: 0x00 => PORB: 0x02',
    'steps': [ {'inputs': [('PINA',0x00)], 'iterations': 5 } ],
    'expected': [('PORTB',0x02)],
    },
    {'description': 'PINA: 0x01 => PORB: 0x01',
    'steps': [ {'inputs': [('PINA',0x01)], 'iterations': 5 } ],
    'expected': [('PORTB',0x01)],
    },  
    ]